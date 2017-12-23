package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-12-3.
 */
public class CopyClassNotSameError extends DecafError {
    private String sour;
    private String dest;

    public CopyClassNotSameError(Location location, String sour, String dest) {
        super(location);
        this.sour = sour;
        this.dest = dest;
    }

    @Override
    protected String getErrMsg() {
        return "For copy expr, the source " + sour +
                " and the destination " + dest + " are not same";
    }
}
