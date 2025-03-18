using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    public sealed class OrderStatusCreator
    {
        public static CancelOrderStatus GenerateCancelOrderStatus(CancelOrder co)
        {
            return new CancelOrderStatus();
        }
        public static NewOrderStatus GenerateNewOrderStatus(Order order)
        {
            return new NewOrderStatus();
        }
        public static ModifyOrderStatus GenerateModifyOrderStatus(ModifyOrder modifyOrder)
        {
            return new ModifyOrderStatus();
        }
    }
}
