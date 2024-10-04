fun hello-ten()
  var i := 0
  while { i < 10 }
    println("hello")
    i := i + 1

// An effect providing a val `is-verbose : bool`
effect is-verbose
  val is-verbose : bool

effect log
  fun log-debug(msg : string) : ()
  fun log-info(msg : string) : ()

fun log(msg : string) : <is-verbose, console> ()
  if is-verbose
  then println("[DEBUG] " ++ msg)
  else println("[INFO ] " ++ msg)

fun serve(port : int) : log ()
  log-debug("Server is preparing for running...")
  // ...
  log-info("Server is running")

effect ctl throw-string<a>(msg : string) : a

effect<a> ctl get() : a

fun safe-div(m : int, n : int) : <throw-string> int {
  if n == 0
    then throw-string("zero division")
    else m / n
}

fun report-get-mn-and-div() : <get<int>, throw-string, console> ()
  println("`get` for `m`")
  val m = get()
  println("`get` for `n`")
  val n = get()
  val result = safe-div(m, n)
  println(m.show() ++ " / " ++ n.show() ++ " = " ++ result.show())

fun to-maybe<a>(action : () -> <throw-string, console> a) : <console> maybe<a>
  with handler
    ctl throw-string(msg)
      println(msg)
      Nothing
    return(x)
      Just(x)
  action()

fun use-get-and-div() : console list<()>
  with
    return(x)
      [x]
    ctl get()
      resume(1) ++ resume(0)
  with
    ctl throw-string(msg)
      println("Fatal: " ++ msg)
  report-get-mn-and-div()

fun main() : <console> ()
  // val h = handler
  //   val is-verbose = False
  // h {
  //   serve(3000)
  // }

  // with
  //   //val is-verbose = True
  //   fun log-debug(msg) println("[DEBUG] " ++ msg)
  //   fun log-info(msg) println("[INFO] " ++ msg)
  // serve(3000)

  // with ctl throw-string(msg)
  //   println("Fatal: " ++ msg)
  // with ctl get()
  //   println("resume by 1")
  //   resume(1)
  //   println("resume by 2")
  //   resume(2)
  // report-get-mn-and-div()

  // println(to-maybe(fn() safe-div(42, 3)))
  // println(to-maybe(fn() safe-div(42, 0)))

  println(use-get-and-div())
