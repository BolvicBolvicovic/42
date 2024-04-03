use clap::{
    Arg,
    command,
    Command,
};

struct Solver {
    x_pow   : f32,
    x       : f32,
    int     : f32,
}

impl Solver {
    pub fn solve(&self) {
        let delta: f32 = self.x * self.x - 4.0 * self.x_pow * self.int;
        if delta < 0.0 {
            println!("There is no solution for {}x^2 + {}x + {} because delta {} is negative.", self.x_pow, self.x, self.int, delta);
        } else if delta == 0.0 {
            println!("There is one solution for {}x^2 + {}x + {}: x = {}.", self.x_pow, self.x, self.int, -self.x / 2.0 * self.x_pow);
        } else {
            println!("There are two solutions for {}x^2 + {}x + {}: x1 = {} and x2 = {}.", self.x_pow, self.x, self.int, -self.x - delta.sqrt() / 2.0 * self.x_pow, -self.x + delta.sqrt() / 2.0 * self.x_pow);
        }

    }
}

fn main() {
    let matches = command!()
        .arg_required_else_help(true)
        .subcommand_required(true)
        .subcommand(
            Command::new("solve")
                .allow_hyphen_values(true)
                .short_flag('s')
                .long_flag("solve")
                .about("Solve reduced simple 2nd degree equation")
                .arg(Arg::new("X_POW_TWO")
                    .default_value("0X^2"))
                .arg(Arg::new("X")
                    .default_value("0X"))
                .arg(Arg::new("Integer")
                    .default_value("0"))
        )
        .get_matches();
    match matches.subcommand() {
        Some(("solve", solve_matches))  => {
            let solver = Solver {
                x_pow   : match solve_matches.get_one::<String>("X_POW_TWO") {
                    Some(string)    => string.parse::<f32>().unwrap(),
                    None            => 0.0,
                },
                x       : match solve_matches.get_one::<String>("X") {
                    Some(string)    => string.parse::<f32>().unwrap(),
                    None            => 0.0,
                },
                int     : match solve_matches.get_one::<String>("Integer") {
                    Some(string)    => string.parse::<f32>().unwrap(),
                    None            => 0.0,
                },
            };
            solver.solve();
        },
        None | Some(_)                  => println!("Command not found.")
    };
}
