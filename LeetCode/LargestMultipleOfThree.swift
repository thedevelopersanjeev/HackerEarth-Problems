class Solution {
    func largestMultipleOfThree(_ digits: [Int]) -> String {
        let remainderArrayOne = [1, 4, 7, 2, 5, 8]
        let remainderArrayTwo = [2, 5, 8, 1, 4, 7]
        var countArray = [Int](repeating: 0, count: 10)
        var sumOfDigits = digits.reduce(0, +)
        for digit in digits {
            countArray[digit] += 1
        }
        while sumOfDigits % 3 != 0 {
            let remaindersToBeRemoved = (sumOfDigits % 3 == 1 ? remainderArrayOne : remainderArrayTwo)
            for remainder in remaindersToBeRemoved {
                if countArray[remainder] > 0 {
                    countArray[remainder] -= 1
                    sumOfDigits -= remainder
                    break
                }
            }
        }
        var answer = ""
        for index in stride(from: 9, to: -1, by: -1) {
            let item = countArray[index]
            answer = answer + String(repeating: String(index), count: item) 
        }
        return (answer.first != "0" ? answer : "0")
    }
}