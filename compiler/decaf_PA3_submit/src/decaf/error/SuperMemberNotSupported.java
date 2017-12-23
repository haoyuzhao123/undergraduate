package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-12-2.
 */
public class SuperMemberNotSupported extends DecafError {

    public SuperMemberNotSupported(Location location) {
        super(location);
    }

    @Override
    protected String getErrMsg() {
        return "super.member_var is not supported";
    }
}
