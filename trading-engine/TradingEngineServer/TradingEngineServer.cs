using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;
using System;
using System.Threading;
using System.Threading.Tasks;
using TradingEngineServer.Core.Configuration;

namespace TradingEngineServer.Core
{
    class TradingEngineServer : BackgroundService, ITradingEngineServer
    {
        private readonly ILogger<TradingEngineServer> _logger;
        private readonly TradingEngineServerConfiguration _tradingEngineServerConfig;
        public TradingEngineServer(ILogger<TradingEngineServer> logger, IOptions<TradingEngineServerConfiguration> config)
        {
            _logger = logger ?? throw new ArgumentNullException(nameof(logger));
            _tradingEngineServerConfig = config.Value ?? throw new ArgumentNullException(nameof(config));
        }

        protected override Task ExecuteAsync(CancellationToken stoppingToken)
        {
            while(!stoppingToken.IsCancellationRequested)
            {

            }
        }
    }
}
