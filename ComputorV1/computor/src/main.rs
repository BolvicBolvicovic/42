use clap::Parser;

#[derive(Parser, Debug)]
struct Equation {
	pattern: Vec<String>,
}

impl Equation {

	fn reduction(&self) -> (Vec<String>, Vec<String>){
		let mut other_side = false;
		let mut r_side = Vec::new();
		let mut l_side = Vec::new();
		for string in self.pattern.iter() {
			if string == "=" { other_side = true; continue; }
			if other_side == false { l_side.push((*string).clone()); }
			else { r_side.push((*string).clone()); }
		}
		if r_side.len() <= l_side.len() {
			let mut is_done = false;
			while !is_done {
				for i in 0..l_side.len()  {
					let mut breaker = false;
					for j in 0..r_side.len() {
						if l_side[i] == r_side[j] {
							l_side.swap_remove(i);
							r_side.swap_remove(j);
							breaker = true;
							break;
						}
					}
					if breaker {
						break;
					}
					if i == l_side.len() - 1 {
						is_done = true;
					}
				}
			}
		} else {
			let mut is_done = false;
			while !is_done {
				for i in 0..r_side.len()  {
					let mut breaker = false;
					for j in 0..l_side.len() {
						if r_side[i] == l_side[j] {
							r_side.swap_remove(i);
							l_side.swap_remove(j);
							breaker = true;
							break;
						}
					}
					if breaker {
						break;
					}
					if i == r_side.len() - 1 {
						is_done = true;
					}
				}
			}
		}
		(l_side, r_side)
	}
}

fn main() {
	let args = Equation::parse().reduction();
	println!("{:?}", args);
}
