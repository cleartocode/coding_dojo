pub fn greplite(lines: Vec<&str>, pat: &str, case_insensitive: bool) -> Vec<String> {
    /*
    Function that filter lines and returns only those with a specific pattern.
    Pseudo:
    var: Out::Vec<String>
    ForEach line in lines:
        If case_insensitive:
            Convert to lowercase
        If line contains pat:
            Append line to Out
        Return

    Rules:
    - Empty pat --> Return all the lines
    - Case Sensitive --> Don't covert to lowercase
    - Keep the same order.
    */
    let mut output = Vec::new();
    for line in lines {
        if case_insensitive {
            if line.to_lowercase().contains(&pat.to_lowercase().as_str()) {
                output.push(line.to_string());
            }
        } else {
            if line.contains(pat) {
                output.push(line.to_string());
            }
        }
    }
    return output;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn case1_basic() {
        let lines = vec!["hola", "mundo", "holanda"];
        let got = greplite(lines, "hol", false);
        assert_eq!(got, vec!["hola".to_string(), "holanda".to_string()]);
    }

    #[test]
    fn case2_case_insensitive() {
        let lines = vec!["Error", "warning", "INFO"];
        let got = greplite(lines, "in", true);
        assert_eq!(got, vec!["warning".to_string(), "INFO".to_string()]);
    }

    #[test]
    fn case3_no_matches() {
        let lines = vec!["a", "b", "c"];
        let got = greplite(lines, "z", false);
        assert!(got.is_empty());
    }
}
