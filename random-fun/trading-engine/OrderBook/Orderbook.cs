using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TradingEngineServer.Instrument;
using TradingEngineServer.Orders;

namespace TradingEngineServer.Orderbook
{
    public class Orderbook : IRetrievalOrderbook
    {
        private readonly Security _instrument;
        private readonly Dictionary<long, OrderbookEntry> _orders = new Dictionary<long, OrderbookEntry>();
        private readonly SortedSet<Limit> _askLimits = new SortedSet<Limit>(AskLimitComparer.Comparer);
        private readonly SortedSet<Limit> _bidLimits = new SortedSet<Limit>(BidLimitComparer.Comparer);

        public Orderbook(Security instrument)
        {
            _instrument = instrument;

        }

        public int Count => _orders.Count;

        public void AddOrder(Order order)
        {
            var baseLimit = new Limit(order.Price);
            AddOrder(order, baseLimit, order.IsBuySide ? _bidLimits : _askLimits, _orders);
        }
        private static void AddOrder(Order order, Limit baseLimit, SortedSet<Limit> limitLevels, Dictionary<long, OrderbookEntry> internalBook)
        {
            if (limitLevels.TryGetValue(baseLimit, out Limit limit))
            {
                OrderbookEntry orderbookEntry = new OrderbookEntry(order, baseLimit);
                if(limit.Head == null)
                {
                    limit.Head = orderbookEntry;
                    limit.Tail = orderbookEntry;
                }
                else
                {
                    OrderbookEntry tailPointer = limit.Tail;
                    tailPointer.Next = orderbookEntry;
                    orderbookEntry.Previous = tailPointer;
                    limit.Tail = orderbookEntry;
                }

            }
            else
            {
                OrderbookEntry orderbookEntry = new OrderbookEntry(order, baseLimit);
                limitLevels.Add(baseLimit);
                baseLimit.Head = orderbookEntry;
                baseLimit.Tail = orderbookEntry;
                internalBook.Add(order.OrderId, orderbookEntry);
            }
        }

        public void ChangeOrder(ModifyOrder modifyOrder)
        {
            if(_orders.TryGetValue(modifyOrder.OrderId, out OrderbookEntry orderbookEntry))
            {
                RemoveOrder(modifyOrder.ToCancelOrder());
                AddOrder(modifyOrder.ToNewOrder(), orderbookEntry.ParentLimit, modifyOrder.IsBuySide ? _bidLimits : _askLimits, _orders);
            }
        }
        public bool ContainsOrder(long orderId)
        {
            return _orders.ContainsKey(orderId);
        }
        public List<OrderbookEntry> GetAskOrders()
        {
            List<OrderbookEntry> orderbookEntries = new List<OrderbookEntry>();
            foreach (var askLimits in _askLimits)
            {
                if(askLimits.IsEmpty)
                    continue;
                else
                {
                    OrderbookEntry askLimitPointer = askLimits.Head;
                    while (askLimitPointer != null)
                    {
                        orderbookEntries.Add(askLimitPointer);
                        askLimitPointer = askLimitPointer.Next;
                    }
                }
            }
            return orderbookEntries;
        }
        public List<OrderbookEntry> GetBidOrders()
        {
            List<OrderbookEntry> orderbookEntries = new List<OrderbookEntry>();
            foreach(var bidLimits in _bidLimits)
            {
                if(bidLimits.IsEmpty)
                    continue;
                else
                {
                    OrderbookEntry bidLimitPointer = bidLimits.Head;
                    while(bidLimitPointer != null)
                    {
                        orderbookEntries.Add(bidLimitPointer);
                        bidLimitPointer = bidLimitPointer.Next;
                    }
                }
            }
            return orderbookEntries;
        }

        public OrderbookSpread GetSpread()
        {
            long ? bestAsk = null, bestBid = null;
            if(_askLimits.Any() && !_askLimits.Min.IsEmpty)
                bestAsk = _askLimits.Min.Price;
            if(_bidLimits.Any() && !_bidLimits.Max.IsEmpty)
                bestBid = _bidLimits.Max.Price;
            return new OrderbookSpread(bestAsk, bestBid);
        }
        public void RemoveOrder(CancelOrder cancelOrder)
        {
            if(_orders.TryGetValue(cancelOrder.OrderId, out var orderbookEntry))
            {
                RemoveOrder(cancelOrder.OrderId, orderbookEntry, _orders);
            }
        }

        private static void RemoveOrder(long orderId, OrderbookEntry orderbookEntry, Dictionary<long, OrderbookEntry> internalBook)
        {
            if (orderbookEntry.Previous != null && orderbookEntry.Next != null)
            {
                orderbookEntry.Next.Previous = orderbookEntry.Previous;
                orderbookEntry.Previous.Next = orderbookEntry.Next;
            }
            else if (orderbookEntry.Previous != null)
            {
                orderbookEntry.Previous.Next = null;
            }
            else if (orderbookEntry.Next != null)
            {
                orderbookEntry.Next.Previous = null;
            }
            if ( orderbookEntry.ParentLimit.Head == orderbookEntry && orderbookEntry.ParentLimit.Tail == orderbookEntry)
            {
                orderbookEntry.ParentLimit.Head = null;
                orderbookEntry.ParentLimit.Tail = null;
            }
            else if (orderbookEntry.ParentLimit.Head == orderbookEntry)
            {
                orderbookEntry.ParentLimit.Head = orderbookEntry.Next;
            }
            else if (orderbookEntry.ParentLimit.Tail == orderbookEntry)
            {
                orderbookEntry.ParentLimit.Tail = orderbookEntry.Previous;
            }
            internalBook.Remove(orderId);
        }
    }
}
