package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-12-3.
 */
public class NotCopyClassError extends DecafError{
    private String type;

    public NotCopyClassError(String type, Location location) {
        super(location);
        this.type = type;
    }

    @Override
    protected String getErrMsg() {
        return "expected class type for copy expr but " + type + " given";
    }
}
