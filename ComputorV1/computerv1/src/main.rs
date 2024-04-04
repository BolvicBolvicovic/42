use std::env::args;

enum Types {
    Plus,
    Minus,
    Equal,
    X,
    XPow,
    Int,
}

fn get_type(arg: &str) -> Option<Types> {
    if arg.contains("X^2") {
        return Some(Types::XPow);
    } else if arg.contains('X') {
        return Some(Types::X);
    } else  {
        let mut is_num = true;
        for c in arg.chars() {
            if !c.is_ascii_digit() {
                is_num = false;
            }
        }
        if is_num {
            return Some(Types::Int);
        }
    }
    match arg {
        "+" => Some(Types::Plus),
        "-" => Some(Types::Minus),
        "=" => Some(Types::Equal),
        _   => None,
    }

}

fn get_num(arg: &str) -> String {
    let mut num = String::new();
    let mut first = true;
    for c in arg.chars() {
        if !c.is_ascii_digit() {
            if first {
                num.push('1');
            }
            break;
        }
        first = false;
        num.push(c);
    }
    num
}

fn main() {
    let mut argv: Vec<String> = args().collect();
    if argv.len() == 1 {
        println!(
"CALCULATOR SOLVING 2ND DEGREE EQUATIONS
USAGE: Expr <intX^2 | intX | int> = Expr <intX^2 | intX | int>
Equal is not necessary but can be used only once.");
        return;
    }
    argv = argv[1..].to_vec();

    let mut x_pow = 0.0;
    let mut x = 0.0;
    let mut int = 0.0;
    let mut next_value_pos = true;
    let mut equal = false;

    for arg in argv.iter() {
        match get_type(arg) {
            Some(r#type) => match r#type {
                Types::Plus => {
                    next_value_pos = true;
                    if equal {next_value_pos = !next_value_pos;}
                },
                Types::Minus => {
                    next_value_pos = false;
                    if equal {next_value_pos = !next_value_pos;}
                },
                Types::Equal => if equal {panic!("= has to be used once");} else {equal = true;},
                Types::X => {
                    let num = get_num(arg);
                    if next_value_pos { x += num.parse::<f64>().unwrap();
                    } else {x -= num.parse::<f64>().unwrap();}
                },
                Types::XPow => {
                    let num = get_num(arg);
                    if next_value_pos { x_pow += num.parse::<f64>().unwrap();
                    } else { x_pow -= num.parse::<f64>().unwrap();}
                },
                Types::Int => if next_value_pos {int += arg.parse::<f64>().unwrap();} else {int -= arg.parse::<f64>().unwrap();},
            },
            None => println!("{} is not a valid argument", arg),
        };
    }

    let delta = (x * x) - (4.0 * x_pow * int);
    
    if delta < 0.0 || (x == 0.0 && x_pow == 0.0) {
        println!("There is no solution for {}x^2 + {}x + {} = 0 because delta {} is negative or a and b equal 0.", x_pow, x, int, delta);
    } else if delta == 0.0 {
        println!("There is one solution for {}x^2 + {}x + {} = 0 -> x = {}.", x_pow, x, int, -x / 2.0 * x_pow);
    } else if x == 0.0 || x_pow == 0.0 { 
        println!("There is one solution for {}x^2 + {}x + {} = 0 -> x = {}.", x_pow, x, int,
        (
            -int / (if x == 0.0 {1.0} else {x}) / (if x_pow == 0.0 {1.0} else {x_pow})
        ));
    } else {
        println!("There are two solutions for {}x^2 + {}x + {} = 0 -> x1 = {} and x2 = {}.", x_pow, x, int, (-x - delta.sqrt()) / 2.0 * x_pow, (-x + delta.sqrt()) / 2.0 * x_pow);
    }
}
