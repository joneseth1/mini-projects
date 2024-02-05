using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Extensions.Options;
using TradingEngineServer.Logging.LoggingConfig;


namespace TradingEngineServer.Logging
{
    public class TextLogger : AbstractLogger, ITextLogger
    {
        private readonly LoggerConfig _loggingConfig;
        public TextLogger(IOptions<LoggerConfig> loggingConfig) : base()
        {
            _loggingConfig = loggingConfig .Value ?? throw new ArgumentNullException(nameof(loggingConfig));
        }
        protected override void Log(LogLevel loglevel, string module, string message) => throw new NotImplementedException();
        public void Dispose() => throw new NotImplementedException();
    }
}
