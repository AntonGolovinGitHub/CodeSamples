using System;
using System.Collections.Generic;
using System.Linq;

namespace GetRealGood.Utils
{
    /// <summary>
    /// Set of utility methods to manipulate collections of objects.
    /// </summary>
    public static class Collections
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static bool IsEmpty(IEnumerable<object> o)
        {
            if (Objects.IsNull(o))
                throw new CollectionsException("Null parameter passed in for o");

            return !o.Any();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        /// /// <exception cref="CollectionsException"></exception>
        public static bool IsNotEmpty(IEnumerable<object> o)
        {
            if (Objects.IsNull(o))
                throw new CollectionsException("Null parameter passed in for o");

            return o.Any();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="coll"></param>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static IList<long> HasNullsAt<T>(IEnumerable<T> coll)
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");

            long i = 0;
            IList<long> s = new List<long>(0);
            foreach (var v in coll)
            {
                if (Objects.IsNull(v))
                    s.Add(i);
                i++;
            }

            return s;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="coll"></param>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static bool HasNulls<T>(IEnumerable<T> coll)
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");



            foreach (var v in coll)
            {
                if (Objects.IsNull(v))
                    return true;
            }

            return false;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="coll"></param>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static long HasNullsCount<T>(IEnumerable<T> coll)
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");

            return HasNullsAt(coll).Count();

        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="coll"></param>
        /// <typeparam name="T"></typeparam>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static T Max<T>(IEnumerable<T> coll) where T : IComparable<T>
        {
        if (Objects.IsNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        if (!coll.Any())
            throw new CollectionsException("Empty enumerable passed in for coll");

            T max;


            var iter = coll.GetEnumerator();
            if (iter.MoveNext())
                max = iter.Current; // first location
            else 
                throw new CollectionsException("Empty collection passed in");

        if (coll.Count() == 1)
            return max;

        iter.Reset();

        foreach (T t in coll) {
            if (Objects.IsNull(t))
                continue;
            if (t.CompareTo(max) == 0)
                continue;
            if (t.CompareTo(max) == 1)
                max = t;
        }

        if(Objects.IsNull(max))
            throw new CollectionsException("Array contains only nulls");
        
        return max;

    }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="coll"></param>
        /// <typeparam name="T"></typeparam>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static T Min<T>(IEnumerable<T> coll) where T : IComparable<T>
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");

            if (!coll.Any())
                throw new CollectionsException("Empty enumerable passed in for coll");

            T min;

            var iter = coll.GetEnumerator();

            if (iter.MoveNext())
                min = iter.Current; // first location
            else
                throw new CollectionsException("Empty collection passed in");

            if (coll.Count() == 1)
                return min;

            iter.Reset();

            foreach (T t in coll)
            {
                if (Objects.IsNull(t))
                    continue;
                if (t.CompareTo(min) == 0)
                    continue;
                if (t.CompareTo(min) == -1)
                    min = t;
            }

            if(Objects.IsNull(min))
                throw new CollectionsException("Array contains only nulls");
            
            return min;   

        }
        
        
        /// <summary>
        /// 
        /// </summary>
        /// <param name="coll"></param>
        /// <typeparam name="T"></typeparam>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static IList<T> Peaks<T>(IEnumerable<T> coll) where T : IComparable<T>
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");

            if (!coll.Any())
                throw new CollectionsException("Empty parameter passed in for coll");

            T max = default(T);
            IList<T> peaks = new List<T>();

            if (coll.Count() == 1)
            {
                var iter = coll.GetEnumerator();
                    iter.MoveNext();
                max = iter.Current;
                return new List<T>() {max};
            }

            int i = 0;
            foreach (T t in coll)
            {
                if (Objects.IsNull(t))
                    continue;
                
                if (i++ == 0)
                {
                    max = t;
                    peaks.Add(max);
                }
                else if (t.CompareTo(max) == 0)
                    peaks.Add(t);
                else if (t.CompareTo(max) == 1)
                {
                    peaks.Clear();
                    max = t;
                    peaks.Add(max);
                }
            }

            if(peaks.Count() == 0)
                throw new CollectionsException("Array contains only nulls");
            
            return peaks;

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="coll"></param>
        /// <typeparam name="T"></typeparam>
        /// <returns></returns>
        /// <exception cref="CollectionsException"></exception>
        public static IList<T> Troughs<T>(IEnumerable<T> coll) where T : IComparable<T>
        {
            if (Objects.IsNull(coll))
                throw new CollectionsException("Null parameter passed in for coll");

            if (!coll.Any())
                throw new CollectionsException("Empty parameter passed in for coll");

            T min = default(T);
            IList<T> troughs = new List<T>();

            if (coll.Count() == 1)
            {
                var iter = coll.GetEnumerator();
                    iter.MoveNext();
                min = iter.Current;
                return new List<T>() {min};
            }

            int i = 0;
            foreach (T t in coll)
            {
                if (Objects.IsNull(t))
                    continue;
                if (i++ == 0)
                {
                    min = t;
                    troughs.Add(min);
                }
                else if (t.CompareTo(min) == 0)
                    troughs.Add(t);
                else if (t.CompareTo(min) == -1)
                {
                    troughs.Clear();
                    min = t;
                    troughs.Add(min);
                }
            }

            if(troughs.Count() == 0)
                throw new CollectionsException("Array contains only nulls");
            
            return troughs;

        }

    }
}