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


def get_possible_sums_naive_version(a, i, sum):
    if sum==0:
        return []
    if i<0:
        return False
    if sum<0:
        return False
    ans2=get_possible_sums_naive_version(a, i-1, sum-a[i])
    ans1=get_possible_sums_naive_version(a, i-1, sum)
    if isinstance(ans2, list):
        return ans2+[a[i]]
    if isinstance(ans1, list):
        return ans1
    return False


def main():
    n = int(input("Enter the length of the array: "))
    a = []  # the list that we are going to work on
    print("Enter the elements of the array: ")
    for i in range(0, n):
        a.append(int(input()))
    total_sum = sum_of_elements(a)
    if total_sum % 2 == 0:
        ans = get_possible_sums_naive_version(a, len(a)-1, total_sum//2)
        if ans:
            print("The given array can be split the following array: ", ans,
                  " and the rest of the elements that it has.")
        else:
            print("The given array cannot be split in such a way.")
    else:
        print("The given array cannot be split in such a way.")

main()
