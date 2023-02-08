import copy


def sum_of_elements(a):
    """
    :param a: the given list
    :return: the sum of all elements in a
    """
    ans = 0
    for x in a:
        ans += x
    return ans


def get_possible_sums_optimized_version(a):
    """
    :param a:
    :return: an array which tells us if a given sum can be obtained from by adding the elements from a
             and another array which contains the elements from a that have that specified sum
    """
    total_sum = sum_of_elements(a)
    sum_elements = [[]] * (total_sum // 2 + 1)
    pos_sum = [False] * (total_sum // 2 + 1)
    pos_sum[0] = True
    prev_pos_sum=copy.deepcopy(pos_sum)
    for x in a:
        for s in range(1, total_sum // 2 + 1):
            if s - x >= 0:
                pos_sum[s] = prev_pos_sum[s] or prev_pos_sum[s - x]
                if pos_sum[s] and (prev_pos_sum[s] is False):
                    sum_elements[s]=copy.deepcopy(sum_elements[s-x])
                    sum_elements[s].append(x)
        pos_sum, prev_pos_sum = prev_pos_sum, pos_sum
    return pos_sum, sum_elements


def main():
    n = int(input("Enter the length of the array: "))
    a = []  # the list that we are going to work on
    print("Enter the elements of the array A: ")
    for i in range(0, n):
        a.append(int(input()))
    total_sum = sum_of_elements(a)
    if total_sum % 2 == 0:
        sums, sum_elements = get_possible_sums_optimized_version(a)
        if sums[total_sum // 2]:
            print("The array A can be split the following array: ", sum_elements[total_sum // 2],
                  " and the rest of its elements.")
        else:
            print("The given array cannot be split in such a way.")
    else:
        print("The given array cannot be split in such a way.")

main()
