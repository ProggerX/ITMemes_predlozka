{
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
		flake-utils.url = "github:numtide/flake-utils";
	};

	outputs = {self, nixpkgs, flake-utils} :
	flake-utils.lib.eachDefaultSystem (system: 
		let pkgs = import nixpkgs { inherit system; };
		in {
			packages.default = pkgs.stdenv.mkDerivation {
				name = "ITMemes-predloz";
				src = ./.;

				nativeBuildInputs = with pkgs; [
					gcc
					bear
				];
				buildInputs = with pkgs; [
					boost.dev
					bzip2
					zlib
					openssl
				];

				buildPhase = "just build";
				installPhase = "cp out $out";
			};
		}
	);
}
