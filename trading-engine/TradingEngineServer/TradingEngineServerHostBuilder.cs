using Microsoft.Extensions.DependencyInjection;
using Microsft.Extensions.Hosting;
using System;
using TradingEngineServer.Core.Configuration;


namespace TradingEngineServer.Core
{
    public sealed class TradingEngineServerHostBuilder
    {
        public static IHost BuildTradingEngineServer()
            => Host.CreateDefaultBuilder().ConfigureServices((Context, services) =>
            {

                services.AddOptions();
                services.Configure<TradingEngineServerConfiguration>(context.Configuration.GetSection(nameof(TradingEngineServerConfiguration)))
            }).Build();

    }
}
