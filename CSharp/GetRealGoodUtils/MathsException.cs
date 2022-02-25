using System;

namespace GetRealGood.Utils
{
    /// <summary>
    /// <code>MathsException</code> is thrown during any exceptional condition for all static methods of the utility <code>Maths</code> class.
    /// </summary>
    public class MathsException : Exception
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="message"></param>
        public MathsException(string message) : base(message)
        {

        }
    }
}