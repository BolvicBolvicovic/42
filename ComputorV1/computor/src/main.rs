use clap::Parser;

#[derive(Parser, Debug)]
struct Equation {
	pattern: Vec<String>,
}

impl Equation {
	fn reduction(&self) {
		let mut other_side = false;
		let mut r_side = Vec::new();
		let mut l_side = Vec::new();
		for string in self.pattern.to_iter() {
			if string == "=" { other_side = true; continue; }
			if other_side == false { r_side.push(string); }
			else { l_side.push(string); }
		}
		for i in 0..(if r_side.len() <= l_side.len() { l_side.len } else {r_side.len() }) {

		}
	}
}

fn main() {
	let args = Equation::parse();//.reduction();
	println!("{:?}", args);
}
