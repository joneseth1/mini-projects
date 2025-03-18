using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Threading.Tasks.Dataflow;
using Microsoft.Extensions.Options;
using TradingEngineServer.Logging.LoggingConfig;


namespace TradingEngineServer.Logging
{
    public class TextLogger : AbstractLogger, ITextLogger
    {
        private readonly LoggerConfig _loggingConfig;
        public TextLogger(IOptions<LoggerConfig> loggingConfig) : base()
        {
            var now = DateTime.Now;
            _loggingConfig = loggingConfig.Value ?? throw new ArgumentNullException(nameof(loggingConfig));
            if(_loggingConfig.LoggerType != LoggerType.Text)
                throw new InvalidOperationException($"{ nameof(TextLogger)} does not much the logger type. ");

            
            string logDir = Path.Combine(_loggingConfig.TextLoggerConfig.Directory, $"{now:yyyy-mm-dd}");
            Directory.CreateDirectory(logDir);

            string baseLogName = Path.ChangeExtension($"{_loggingConfig.TextLoggerConfig.FileName}-{now:HH_mm_ss}",
                _loggingConfig.TextLoggerConfig.FileExtension);
            string filepath = Path.Combine(logDir,baseLogName);

            _ = Task.Run(() => LogAsync(filepath, _logQueue, _tokenSource.Token));
        }

        private static async Task LogAsync(string filepath, BufferBlock<LogInformation> logQueue, CancellationToken token)
        {
            using var fs = new FileStream(filepath, FileMode.CreateNew, FileAccess.Write, FileShare.Read);
            using var writer = new StreamWriter(fs, Encoding.UTF8);
            try
            {
                while (true)
                {
                    var logItem = await logQueue.ReceiveAsync(token).ConfigureAwait(false);
                    string formattedMesg = FormatLogItem(logItem);
                        await writer.WriteAsync(formattedMesg).ConfigureAwait(false);
                }
            }
            catch (OperationCanceledException)
            { }
        }

        private static string FormatLogItem(LogInformation logItem)
        {
            return $"[{logItem.Now:yyyy-MM-dd HH-mm-ss.ffffff}] [{logItem.ThreadName, -30}:{logItem.ThreadId:000}] " +
                $"[{logItem.loglevel}] {logItem.Message}";
        }

        protected override void Log(LogLevel loglevel, string module, string message)
        {
            _logQueue.Post(new LogInformation(loglevel,module,message,DateTime.Now, Thread.CurrentThread.ManagedThreadId, Thread.CurrentThread.Name));
        }

        ~TextLogger()
        {
            Dispose(false);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            lock(_lock)
            {
                if(_disposed)
                    return;
                _disposed = true;
            }

            if (disposing)
            {
                _tokenSource.Cancel();
                _tokenSource.Dispose();
            }

        }

        private readonly BufferBlock<LogInformation> _logQueue = new BufferBlock<LogInformation>();
        private readonly CancellationTokenSource _tokenSource = new CancellationTokenSource();
        private readonly object _lock = new object();
        private bool _disposed = false;

    }
}
