export class Strings {

    public static toUpper(o: string) : string {
        if(o == null)
            throw new StringsError("o == null");
        if(o.length == 0)
            return o;
        return o.toUpperCase();
    }

    public static toLower(o: string) : string {
        if(o == null)
            throw new StringsError("o == null");
        if(o.length == 0)
            return o;
        return o.toLowerCase();
    }

    public static split(o: string, token : string, trim : boolean) : string[] {
        if(o == null)
            throw new StringsError("o == null");

        if(token == null)
            throw new StringsError("token == null");

        if(token.length == 0)
            throw new StringsError("token.length == 0");

        if(o.length == 0)
            return [o];

        if(trim)
            o = o.trim();

        let result = o.split(token);

        if (trim) {
            for (let i in result) {
                i = i.trim();
            }
        }

        return result;

    }

    public static concat(o: string[], token : string, trim : boolean) : string {

        if(o == null)
            throw new StringsError("o == null");

        if(o.length == 0)
            throw new StringsError("o.length == 0");

        if(token == null)
            throw new StringsError("token == null");

        let result = "";

            for (let i of o) {
                if(trim) i = i.trim();
                result += i + token;
            }

         return result.substring(0, result.length - token.length);

    }

    public static replace(o: string, token1 : string, token2 : string, trim : boolean) : string {

        if(o == null)
            throw new StringsError("o == null");

        if(o.length == 0)
            return o;

        if(token1 == null)
            throw new StringsError("token1 == null");

        if(token1.length == 0)
            throw new StringsError("token1.length == 0");

        if(token2 == null)
            throw new StringsError("token2 == null");

        if(trim)
            o = o.trim();

        while (o.indexOf(token1) != -1) {
            o = o.replace(token1, token2);
        }
        return o;

    }

}

export class StringsError {

    constructor(s : string) {
        this.message = s;
    }

    message : string
}