package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-12-2.
 */
public class ParentNotFoundError extends DecafError {
    private String name;

    public ParentNotFoundError(Location location, String name) {
        super(location);
        this.name = name;
    }

    @Override
    protected String getErrMsg() {
        return "no parent class exist for " + name;
    }
}
