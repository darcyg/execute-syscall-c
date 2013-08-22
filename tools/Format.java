import java.io.*;

public class Format {
  
  
  public static void main(String[] args) {
    BufferedReader br = null;
    try {
			String line;
 
			br = new BufferedReader(new FileReader("input"));
      FileWriter fstream = new FileWriter("output");
      BufferedWriter out = new BufferedWriter(fstream);
      
			while ((line = br.readLine()) != null) {
			  int index = line.indexOf('(');
			  if(index > 0) {
			    String word = line.substring(0, index);
				  
				  /*
				  // {"close",   execute_close},
				  out.write("{\"" + word + "\",");
				  for(int i=1; i<=23-word.length(); i++)
				    out.write(" ");
				  out.write("execute_" + word + ",");
				  for(int i=1; i<=23-word.length(); i++)
				    out.write(" ");
				  out.write("0},\n");
				  */
				  
				  /*
				  // int execute_close();
				  out.write("int execute_" + word + "();\n");
				  */
				  

          out.write("/*\n  " + word.toUpperCase() + "\n  \n  \n*/"
                  + "\nint execute_" + word + "() {\n  \n  return 0;"
                  + "\n} // execute_" + word + "\n\n\n");

				  
			  }
			}
			
      //Close the output stream
      out.close();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null) br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
  }
  
  
}
