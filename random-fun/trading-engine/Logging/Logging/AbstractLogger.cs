using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Logging
{
    public abstract class AbstractLogger : ILogger
    {
        protected AbstractLogger()
        { }
        public void Debug(string module, string message) => Log(LogLevel.Debug, module, message);
        public void Debug(string module, Exception exception) => Log(LogLevel.Debug, module, $"{exception}");
        public void Information(string module, Exception exception) => Log(LogLevel.Debug, module, $"{exception}");
        public void Infromation(string module, string message) => Log(LogLevel.Debug, module, message);
        public void Warning(string module, string message) => Log(LogLevel.Debug, module, message);
        public void Warning(string module, Exception exception) => Log(LogLevel.Debug, module, $"{exception}");
        public void Error(string module, string message) => Log(LogLevel.Debug, module, message);
        public void Error(string module, Exception exception) => Log(LogLevel.Debug, module, $"{exception}");

 
        protected abstract void Log(LogLevel loglevel, string module, string message);
    }
}
