package decaf.error;

import decaf.Location;

/**
 * Created by zhy on 17-11-30.
 */
public class IncompatACaseExprError extends DecafError {

    private String expected;

    private String expr;

    public IncompatACaseExprError(Location location, String expected, String expr) {
        super(location);
        this.expected = expected;
        this.expr = expr;
    }

    @Override
    protected String getErrMsg() {
        return "type: " + expr
                + " is different with other expr's type " + expected;
    }
}
