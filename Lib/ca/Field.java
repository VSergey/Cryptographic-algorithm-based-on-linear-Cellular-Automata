package ca;

public class Field {
    private static final int lenght = 8;

    private final Rule rule;
    private boolean[] current;
    private boolean[] next;

    public Field(Rule rule, int field) {
        this.rule = rule;

        current = new boolean[lenght];
        current = new boolean[lenght];

        for (int i = 0, j = lenght-1; i < lenght; ++i, --j) {
            current[j] = (field & (1 << i)) != 0;
        }
    }

    public int eval() {
        for (int i = 1; i < lenght-1; ++i)
            next[i] = rule.getAt(getCurrent(i - 1) * 4 + getCurrent(i) * 2 + getCurrent(i + 1));
        next[0] = rule.getAt(getCurrent(lenght - 1) * 4 + getCurrent(0) * 2 + getCurrent(1));
        next[lenght - 1] = rule.getAt(getCurrent(lenght - 2) * 4 + getCurrent(lenght - 1) * 2 + getCurrent(0));
        System.arraycopy(next, 0, current, 0, lenght);
        int field = 0;
        for (int i = 0, j = lenght - 1; i < lenght; ++i, --j)
            field += getCurrent(j) * (1 << i);
        return field;
    }

    private int getCurrent(int i) {
        return current[i] ? 1 : 0;
    }
}
