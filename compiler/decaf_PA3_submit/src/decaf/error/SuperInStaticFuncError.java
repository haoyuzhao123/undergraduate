package decaf.error;

/**
 * Created by zhy on 17-11-29.
 */

import decaf.Location;

/**
 * can not use this in static function
 * PA2
 */
public class SuperInStaticFuncError extends DecafError {

    public SuperInStaticFuncError(Location location) {
        super(location);
    }

    @Override
    protected String getErrMsg() {
        return "can not use super in static function";
    }

}

