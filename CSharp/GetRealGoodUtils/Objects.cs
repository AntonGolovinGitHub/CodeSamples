namespace GetRealGood.Utils
{
    /// <summary>
    /// 
    /// </summary>
    public static class Objects
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        public static bool IsNull(object o)
        {
            return o == null;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        public static bool IsNotNull(object o)
        {
            return o != null;
        }
    }
}
