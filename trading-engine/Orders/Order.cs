using System;
using System.Collections.Generic;
using System.Text;
using TradingEgnineServer.Orders;

namespace TradingEngineServer.Orders
{
    public class Order : IOrderCore
    {
        public Order(IOrderCore orderCore, long price, uint quantity, bool isBuySide)
        {
            Price = price;
            IsBuySide = isBuySide;
            InitialQuantity = quantity;
            CurrentQuantity = quantity;

            _orderCore = orderCore;
        }
        
        public long Price { get; private set; }
        public uint InitialQuantity { get; private set;}
        public uint CurrentQuantity { get; private set; }
        public bool IsBuySide { get; private set;}

        public void IncreaseQuantity(uint quantityDelta)
        {
            if(quantityDelta > CurrentQuantity)
                throw new InvalidOperationException($"Underflow for OrderId={OrderId}");
            CurrentQuantity += quantityDelta;
        }
        public void DecreaseQuantity(uint quantityDelta)
        {
            CurrentQuantity -= quantityDelta;
        }

        private readonly IOrderCore _orderCore;
    }
}
