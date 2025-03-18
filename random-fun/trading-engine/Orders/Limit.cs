using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    public class Limit
    {
        public Limit(long Price)
        {
            Price = Price;
        }

        public long Price { get; private set; }
        public OrderbookEntry Head { get; set; }
        public OrderbookEntry Tail{ get; set; }

        public uint GetLevelOrderCount()
        {
            uint orderCount = 0; 
            OrderbookEntry head = Head;
            while (head != null)
            {
                if (head.CurrentOrder.CurrentQuantity != 0)
                    orderCount++;
                head = head.Next;
            } 
            return orderCount;
        }

        public uint GetLevelOrderQuantity()
        {
            uint quantity = 0;
            OrderbookEntry head = Head;
            while (head != null)
            {
                quantity += head.CurrentOrder.CurrentQuantity;
                head = head.Next;
            }
            return quantity;
        }

        public List<OrderRecord> GetLevelOrderRecords()
        {
            List<OrderRecord> records = new List<OrderRecord>();
            OrderbookEntry head =Head;
            uint theoreticalQueuePosition = 0;
            while (head != null)
            {
                var currentOrder = head.CurrentOrder;
                if(currentOrder.CurrentQuantity != 0)
                    records.Add(new OrderRecord(currentOrder.OrderId, currentOrder.CurrentQuantity,
                        Price, currentOrder.IsBuySide, currentOrder.Username, currentOrder.SecurityId,
                        theoreticalQueuePosition));
                theoreticalQueuePosition++;
                head = head.Next;
            }
            return records;
        }

        public bool IsEmpty
        {
            get
            {
                return Head == null && Tail == null;
            }
        }
        public Side Side
        {
            get
            {
                if(IsEmpty)
                    return Side.Unkown;
                else
                {
                    return Head.CurrentOrder.IsBuySide ? Side.Bid : Side.Ask;
                }
            }
        }
    }
}
