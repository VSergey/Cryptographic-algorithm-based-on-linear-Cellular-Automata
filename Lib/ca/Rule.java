package ca;

public class Rule {
    private boolean[] state;

    public Rule(int number) {
        state = new  boolean[8];
        for (int i = 0; i < 8; ++i) {
            state[i] = (number & (1 << i)) != 0;
        }
    }

    public boolean getAt(int neighbourhood) {
        return state[neighbourhood];
    }
}
