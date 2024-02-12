using System;

namespace TradingEgnineServer.Orders
{
    public interface IOrderCore
    {
        public long OrderId { get; }
        public string Username { get; }
        public int SecurityId { get; }
    }
}
