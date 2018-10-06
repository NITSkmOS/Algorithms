defmodule Sort do
  @moduledoc """
  QuickSort Algorithm
  - If the list is empty, return the list and terminate.
  - If the list length is one, return the list and terminate.
  - Choose a pivot element in the list.
  - Take all of the elements that are less than or equal to the pivot and use quicksort on them.
  - Take all of the elements that are greater than the pivot and use quicksort on them.
  - Return the concatenation of the quicksorted list of elements that are less than or equal to
    the pivot, the pivot, and the quicksorted list of elements that are greater than the pivot.
  """

  def quicksort(list = []), do: list
  def quicksort(list = [_]), do: list

  def quicksort(list) do
    [pivot | _] = list

    %{less: less, more: more, pivotlist: pivotlist} =
      Enum.reduce(
        list,
        %{less: [], more: [], pivotlist: []},
        fn cur, acc -> update_state(pivot, cur, acc) end
      )

    quicksort(less) ++ pivotlist ++ quicksort(more)
  end

  defp update_state(pivot, value, state = %{less: less}) when value < pivot do
    %{state | less: less ++ [value]}
  end

  defp update_state(pivot, value, state = %{more: more}) when value > pivot do
    %{state | more: more ++ [value]}
  end

  defp update_state(pivot, _value, state = %{pivotlist: pivotlist}) do
    %{state | pivotlist: pivotlist ++ [pivot]}
  end
end


# Main code

[4, 5, 6, 1, 3, 2]
|> Sort.quicksort()
|> IO.inspect(label: "Sorted list")
