import sys

def run_bf(code):
    mem = [0] * 30000
    ptr = 0
    pc = 0
    output = []
    length = len(code)
    
    while pc < length:
        cmd = code[pc]
        if cmd == '+':
            mem[ptr] = (mem[ptr] + 1) & 255
        elif cmd == '-':
            mem[ptr] = (mem[ptr] - 1) & 255
        elif cmd == '>':
            ptr += 1
        elif cmd == '<':
            ptr -= 1
        elif cmd == '.':
            output.append(chr(mem[ptr]))
        elif cmd == ',':
            pass  # Input not needed
        elif cmd == '[':
            if mem[ptr] == 0:
                depth = 1
                while depth > 0:
                    pc += 1
                    if pc >= length:
                        break
                    if code[pc] == '[':
                        depth += 1
                    elif code[pc] == ']':
                        depth -= 1
        elif cmd == ']':
            if mem[ptr] != 0:
                depth = 1
                while depth > 0:
                    pc -= 1
                    if pc < 0:
                        break
                    if code[pc] == ']':
                        depth += 1
                    elif code[pc] == '[':
                        depth -= 1
        pc += 1
    
    return ''.join(output)

if __name__ == "__main__":
    with open(sys.argv[1], 'r') as f:
        code = f.read()
    result = run_bf(code)
    sys.stdout.write(result)
