fin = open("input", "r")
fout = open("output", "w")

flags = {}
write_line = ""
for line in fin:
  """ 
  Translate flags to a dictionaly of flags.

  Given Format:
  PF_UNSPEC 0 /* Unspecified.  */
  PF_LOCAL  1 /* Local to host (pipes and file-domain).  */
  PF_UNIX   PF_LOCAL /* POSIX name for PF_LOCAL.  */

  Desired Format:
  "PF_UNSPEC":0, "PF_LOCAL":1, "PF_UNIX":1,
  """

  line_parts = line.split()
  flag = line_parts[0]
  flag_value = line_parts[1]
  
  try:
    flag_value = int(flag_value)
    flags[flag] = flag_value
  except ValueError:
    # defined in terms of another flag.
    flags[flag] = flags[flag_value]
  
  write_flag = "'" + flag + "':" + str(flags[flag]) + ", "
  if len(write_line + write_flag) >= 50:
    fout.write(write_line + "\n")
    write_line = ""
  
  write_line += write_flag

fout.write(write_line + "\n")
fin.close()
fout.close()
  