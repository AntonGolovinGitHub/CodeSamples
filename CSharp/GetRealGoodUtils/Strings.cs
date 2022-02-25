using System.Collections.Generic;
using System.Linq;

namespace GetRealGood.Utils
{
    /// <summary>
    /// 
    /// </summary>
    public static class Strings
    {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static string ToUpper(string s)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            return s.ToUpperInvariant();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static string ToLower(string s)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            return s.ToLowerInvariant();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="token"></param>
        /// <param name="trim"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static IList<string> Split(string s, char token, bool trim)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            if(s.Length == 0)
                return new List<string>(0);
            
            IList<string> result = s.Split(token).ToList();

            if (trim)
            {
                result = result.Select(a => a.Trim()).ToList();
            }

            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="token"></param>
        /// <param name="trim"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static string Concat(IList<string> s, string token, bool trim)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            string result = new string("");
            int counter = 0;
            int length = s.Count() - 1;

            foreach (var e in s)
            {
                if (trim)
                {
                    if (e.Length == 0)
                        continue;
                    result += e.Trim();
                }
                else
                {
                    if (e.Length == 0)
                        continue;
                    result += e;
                }

                if (Objects.IsNull(token))
                    continue;
                else
                {
                    if (counter < length)
                    {
                        result += token;
                        counter++;
                    }

                }

            }

            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="orig"></param>
        /// <param name="w"></param>
        /// /// <param name="trim"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static string Replace(string s, char orig, char w, bool trim)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            if (trim)
                s = s.Trim();

            char[] chars = s.ToCharArray();

            for (var i = 0; i < chars.Length; i++)
                if (chars[i] == orig)
                    chars[i] = w;

            return new string(chars);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="orig"></param>
        /// <param name="w"></param>
        /// <returns></returns>
        /// <exception cref="StringsException"></exception>
        public static string Replace(string s, char orig, char w)
        {
            if (Objects.IsNull(s))
                throw new StringsException("Null value passed in for s");

            return Replace(s, orig, w, false);
        }
    }
}



