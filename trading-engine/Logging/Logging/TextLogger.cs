using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
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
            _loggingConfig = loggingConfig.Value ?? throw new ArgumentNullException(nameof(loggingConfig));
        }

        private static void LogAsync(string filepath, BufferBlock<LogInformation> logQueue, CancellationToken toekn)
        {
            using var fs = new FileStream(filepath, FileMode.CreateNew, FileAccess.Write, FileShare.Read);
            using var writer = new StreamWriter(fs, Encoding.UTF8);

        }

        protected override void Log(LogLevel loglevel, string module, string message)
        {
            _logQueue.Post(new LogInformation(loglevel,module,message,DateTime.Now, Thread.CurrentThread.ManagedThreadId, Thread.CurrentThread.Name));
        }
        public void Dispose() => throw new NotImplementedException();

        private readonly BufferBlock<LogInformation> _logQueue = new BufferBlock<LogInformation>();
    }
}
