fn main() {
    use Instructions::{ADD, PUSH, SUB};
    let program: Vec<Instructions> = vec![PUSH(3), PUSH(4), ADD, PUSH(5), SUB];
    let eval = virtual_machine(program);
    println!("Program eval: {}", eval);
}

enum Instructions {
    PUSH(u32),
    ADD,
    SUB,
}

fn virtual_machine(program: Vec<Instructions>) -> u32 {
    let mut stack: Vec<u32> = Vec::new();
    let mut stack_pointer = 0;

    for current_instruction in program.iter() {
        match current_instruction {
            Instructions::PUSH(val) => {
                stack.push(*val);
                stack_pointer += 1;
            }
            Instructions::ADD => {
                let right = stack[stack_pointer - 1];
                stack_pointer -= 1;
                let left = stack[stack_pointer - 1];
                stack_pointer -= 1;
                stack[stack_pointer] = left + right;
                stack_pointer += 1;
            }
            Instructions::SUB => {
                let right = stack[stack_pointer - 1];
                stack_pointer -= 1;
                let left = stack[stack_pointer - 1];
                stack_pointer -= 1;
                stack[stack_pointer] = left + right;
                stack_pointer += 1;
            }
        }
    }
    stack[stack_pointer - 1]
}
