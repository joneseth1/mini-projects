using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    public class ModifyOrder : IOrderCore
    {
        public ModifyOrder(IOrderCore orderCore, long modifyPrice, uint modifyQuantity, bool isBuySide)
        {
            ModifyPrice = modifyPrice;
            ModifyQuantity = modifyQuantity;
            IsBuySide = isBuySide;
            
            _orderCore = orderCore;

        }
        public long ModifyPrice { get; private set; }
        public uint ModifyQuantity { get; private set; }
        public bool IsBuySide { get; private set;}

        public long OrderId => _orderCore.OrderId;

        public string Username => _orderCore.Username;

        public CancelOrder ToCancelOrder()
        {
            return new CancelOrder(this);
        }
        public Order ToNewOrder()
        {
            return new Order(this);

        }

        public int SecurityId => _orderCore.SecurityId;

        private readonly IOrderCore _orderCore;
    }
}
