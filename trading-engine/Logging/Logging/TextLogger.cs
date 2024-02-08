using System;
using System.Collections.Generic;
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
        protected override void Log(LogLevel loglevel, string module, string message)
        {
            _logQueue.Post(new LogInformation(loglevel,module,message,DateTime.Now, Thread.CurrentThread.ManagedThreadId, Thread.CurrentThread.Name));
        }
        public void Dispose() => throw new NotImplementedException();

        private readonly BufferBlock<LogInformation> _logQueue = new BufferBlock<LogInformation>();
    }
}
