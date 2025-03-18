using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.DependencyInjection;
using TradingEngineServer.Core.Configuration;
using TradingEngineServer.Logging;
using TradingEngineServer.Logging.LoggingConfig;

namespace TradingEngineServer.Core
{
     public sealed class TradingEngineServerHostBuilder
    {
        public static IHost BuildTradingEngineServer()
            => Host.CreateDefaultBuilder().ConfigureServices((context, services) 
                =>
            {
                services.AddOptions();
                services.Configure<TradingEngineServerConfiguration>(context.Configuration.GetSection(nameof(TradingEngineServerConfiguration)));
                services.Configure<LoggerConfig>(context.Configuration.GetSection(nameof(LoggerConfig)));

                services.AddSingleton<ITradingEngineServer, TradingEngineServer>();
                services.AddSingleton<ITextLogger, TextLogger>();

                services.AddHostedService<TradingEngineServer>();
            }).Build();
    }
}
