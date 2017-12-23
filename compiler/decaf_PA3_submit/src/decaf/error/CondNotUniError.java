package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-11-30.
 */
public class CondNotUniError extends DecafError {

    public CondNotUniError(Location location) {
        super(location);
    }

    @Override
    protected String getErrMsg() {
        return "condition is not unique";
    }
}
