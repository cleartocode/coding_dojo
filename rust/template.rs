pub fn solve(/* params */) -> /* tipo salida */ {
    /*
    SPEC:
    - Entradas:
    - Salidas:
    - Reglas/empates:
    - Edge cases:
    */
    // TODO: implementar
    unimplemented!()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn table() {
        let cases = vec![
            ((/* arg1 */, /* arg2 */), /* expected */),
            ((/* ... */), /* expected */),
            ((/* ... */), /* expected */),
        ];

        for (i, (inp, expected)) in cases.into_iter().enumerate() {
            let (/* arg1, arg2, ... */) = inp;
            let got = solve(/* arg1, arg2, ... */);
            assert_eq!(got, expected, "case {}", i+1);
        }
    }
}
