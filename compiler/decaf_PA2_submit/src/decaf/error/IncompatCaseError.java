package decaf.error;

import decaf.Location;

/**
 * zhy
 */
public class IncompatCaseError extends DecafError {

    private String expected;

    private String expr;

    public IncompatCaseError(Location location, String expected, String expr) {
        super(location);
        this.expected = expected;
        this.expr = expr;
    }

    @Override
    protected String getErrMsg() {
        return "incompatible case expr: " + expr
                + " given, but " + expected + " expected";
    }

}
