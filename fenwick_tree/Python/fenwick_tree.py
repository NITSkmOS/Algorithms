def lsb(x):
    """Returns the Last Significant Bit (LSB) of x"""
    return x & -x


class FenwickTree:
    """A simple implementation of a Fenwick tree"""

    def __init__(self, size):
        self.data = [0] * (size + 1)  # Initialise 0-filled data array

    def _cumulative_sum(self, right):
        """
        Returns the sum from 0 to right (inclusive)

        :param right: The inclusive right index
        :return: sum([left; right])
        """
        res = 0
        index = right + 1  # Convert to 1-based index
        while index > 0:
            res += self.data[index]
            index -= lsb(index)

        return res

    def sum(self, left, right):
        """
        Returns the sum from left (inclusive) to right (inclusive)

        :param right: The inclusive right index
        :param left: The inclusive left index
        :return: sum([left; right])
        """
        return self._cumulative_sum(right) - self._cumulative_sum(left - 1)

    def add(self, index, diff):
        """
        Add the difference to the data index

        :param index: The index to update
        :param diff: The amount to add to that index
        """
        index += 1  # Convert to 1-based index

        while index < len(self.data):
            self.data[index] += diff
            index += lsb(index)


def main():
    tree = FenwickTree(8)

    # Set initial value(by default it's 0)
    for i in range(8):
        tree.add(i, i)

    # Now it's 0, 1, 2, 3, 4, 5, 6, 7

    # [0, 1, 2, 3, 4, 5, 6, 7]
    #  ^--------------------^
    # 0 + 1 + 2...+ 7 = 28
    assert tree.sum(0, 7) == 28

    # [0, 1, 2, 3, 4, 5, 6, 7]
    #  ^-----^
    #  4 + 5 + 6 = 15
    assert tree.sum(4, 6) == 15

    # [0, 1, 2, 3, 4, 5, 6, 7]
    #  ^--------^
    #  0 + 1 + 2 + 3 = 6
    assert tree.sum(0, 3) == 6

    # Update the numbers again
    for i in range(8):
        tree.add(i, 1 - i)
        # Initial value i
        # Added: 1 - i
        # Res: i + 1 - i = 1

    # [1, 1, 1, 1, 1, 1, 1, 1]
    #  ^--------------------^
    # 1 * 8 = 8
    assert tree.sum(0, 7) == 8
    print("Tests passed")


if __name__ == "__main__":
    main()
