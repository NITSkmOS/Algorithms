public class fenwick_tree {
    private int[] data;

    public fenwick_tree(int size) {
        data = new int[size + 1];
    }

    /**
     * Returns the sum from 0 to right (inclusive)
     * @param right the inclusive right index
     * @return sum([0; right])
     */
    public int sum(int right) {
        int sum = 0;
        int index = right + 1;// Convert to 1-based index
        for (; index > 0; index -= LSB(index)) {
            sum += data[index];
        }
        return sum;
    }

    /**
     * Returns the sum from left (inclusive) to right (inclusive)
     * @param left the inclusive left index
     * @param right the inclusive right index
     * @return sum([left; right])
     */
    public int sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    /**
     * Add the difference to the data index
     * @param index the index to update
     * @param diff the amount to add to that index
     */
    public void add(int index, int diff) {
        index++; // Convert to 1-based index
        for (; index < data.length; index += LSB(index)) {
            data[index] += diff;
        }
    }

    /**
     * Returns the tree's capacity
     * @return tree sizes
     */
    public int getSize() {
        return data.length - 1;// The 0 index isn't used
    }

    private static int LSB(int x) {
        // Last Significant Bit
        return x & -x;
    }


    /**
     * Example usage
     * run with "java -ea fenwick_tree" to enable assertions
     */
    public static void main(String[] args) {
        fenwick_tree tree = new fenwick_tree(8);

        // Set initial value (by default it's 0)
        for (int i = 0; i < 8; i++) {
            tree.add(i, i);
        }
        // Now it's 0, 1, 2, 3, 4, 5, 6, 7

        // [0, 1, 2, 3, 4, 5, 6, 7]
        //  ^--------------------^
        // 0 + 1 + 2 ... + 7 = 28
        assert tree.sum(0, 7) == 28;

        // [0, 1, 2, 3, 4, 5, 6, 7]
        //              ^-----^
        // 4 + 5 + 6 = 15
        assert tree.sum(4, 6) == 15;

        // [0, 1, 2, 3, 4, 5, 6, 7]
        //  ^--------^
        // 0 + 1 + 2 + 3 = 6
        assert tree.sum(3) == 6;

        // Update the numbers again
        for (int i = 0; i < 8; i++) {
            tree.add(i, 1 - i);
            // Initial value i
            // Added: 1 - i
            // Res: i + 1 - i = 1
        }

        // [1, 1, 1, 1, 1, 1, 1, 1]
        //  ^--------------------^
        // 1 * 8 = 8
        assert tree.sum(0, 7) == 8;
        System.out.println("Tests passed");
    }
}
