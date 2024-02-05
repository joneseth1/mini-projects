using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Logging.LoggingConfig
{
    public class LoggerConfig
    {
        public LoggerType LoggerType { get; set; }
        public TextLoggerConfig TextLoggerConfig { get; set; }

    }

    public class TextLoggerConfig
    {
        public string Directory { get; set; }
        public string FileName { get; set; }
        public string FileExtension { get; set; }

    }

}
