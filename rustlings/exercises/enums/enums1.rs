// enums1.rs
//
// No hints this time! ;)


#[derive(Debug)]
enum Message {
    // TODO: define a few types of messages as used below
	SEGFAULT,
	Echo,
	Move,
	ChangeColor,
}

fn main() {
    println!("{:?}", Message::SEGFAULT);
    println!("{:?}", Message::Echo);
    println!("{:?}", Message::Move);
    println!("{:?}", Message::ChangeColor);
}
