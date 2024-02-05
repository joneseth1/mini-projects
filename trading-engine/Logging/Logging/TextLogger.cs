using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Logging
{
    public class TextLogger : AbstractLogger, ITextLogger
    {
        protected override void Log(LogLevel loglevel, string module, string message) => throw new NotImplementedException();
        public void Dispose() => throw new NotImplementedException();
    }
}
