package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-11-30.
 */
public class DoCondError extends DecafError {
    public String typename;

    public DoCondError(Location location, String typename) {
        super(location);
        this.typename = typename;
    }

    @Override
    protected String getErrMsg() {
        return "The condition of Do Stmt requestd type bool but " + typename + " given";
    }
}
