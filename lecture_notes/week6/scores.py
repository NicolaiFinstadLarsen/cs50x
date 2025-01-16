scores = [72,73,33]
scores2 = []

for i in range(3):
    input_score = int(input("score: "))
    scores2.append(input_score)

avg = sum(scores) / len(scores)
print(f"Average: {avg:.3f}")

avg2 = sum(scores2) / len(scores2)
print(f"Average 2: {avg2:.5f}")
