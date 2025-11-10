import re

def extract_time_values(file_path):
    """
    从文件中提取时间数据（单位：ms）
    :param file_path: 文件路径
    :return: 时间数据列表
    """
    time_values = []
    with open(file_path, "r") as file:
        for line in file:
            match = re.search(r"([0-9.]+)\s*ms", line)
            if match:
                time_values.append(float(match.group(1)))
    return time_values

def calculate_statistics(time_values):
    """
    计算时间数据的统计信息
    :param time_values: 时间数据列表
    :return: 平均值、最大值、最小值
    """
    if not time_values:
        return None, None, None
    average_time = sum(time_values) / len(time_values)
    max_time = max(time_values)
    min_time = min(time_values)
    return average_time, max_time, min_time

def main():
    file_path = "MultiBehaviorJudge.txt"
    time_values = extract_time_values(file_path)
    average_time, max_time, min_time = calculate_statistics(time_values)

    if time_values:
        print(f"平均值: {average_time:.6f} ms")
        print(f"最大值: {max_time:.6f} ms")
        print(f"最小值: {min_time:.6f} ms")
    else:
        print("未找到任何时间数据")

if __name__ == "__main__":
    main()
