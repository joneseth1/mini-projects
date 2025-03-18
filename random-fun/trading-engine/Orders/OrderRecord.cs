using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    public record OrderRecord(long OrderId, uint Quantity, long Price, bool IsbuySide, string Username, int SecurityId,
        uint TheroticalQueuePos); 
}



namespace System.Runtime.CompilerServices
{
    internal static class IsExternalInit { };
}
