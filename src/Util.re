[@bs.val] external __dirname: string = "";
[@bs.module "path"] [@bs.variadic]
external resolve: array(string) => string = "";
[@bs.deriving abstract]
type readdirSyncOptions = {
  [@bs.optional]
  withFileTypes: bool,
};
type dirent = {
  .
  "name": string,
  [@bs.meth] "isDirectory": unit => bool,
};
[@bs.module "fs"]
external readdirSync: (string, readdirSyncOptions) => array(dirent) = "";

// ------------------------------------------------------------------------- //
// ------------------------------------------------------------------------- //
// ------------------------------------------------------------------------- //

let filterItemsList = (~ignore=?, itemsList: list(dirent)) => {
  switch (ignore) {
  | None => itemsList
  | Some(value) => itemsList |> List.filter(item => item##name != value)
  };
};

let getAbsolutePath = (path: string): string => {
  resolve([|__dirname, path|]);
};

let padText = (padding: int, text: string): string => {
  String.make(padding, ' ') ++ text;
};

let rec printDir = (~padding: int, ~ignore=?, path: string): unit => {
  let absolutePath = getAbsolutePath(path);
  let options = readdirSyncOptions(~withFileTypes=true, ());
  readdirSync(absolutePath, options)
  |> Array.to_list
  |> filterItemsList(~ignore?)
  |> List.iter((item: dirent) =>
       if (!item##isDirectory()) {
         {js|📄|js} ++ " " ++ item##name |> padText(padding) |> Js.log;
       } else {
         {js|📁|js} ++ " " ++ item##name |> padText(padding) |> Js.log;
         printDir(
           ~padding=padding + 1,
           ~ignore?,
           absolutePath ++ "/" ++ item##name,
         );
       }
     );
  // ----------------------------------------------------------------------- //
  // let absPath = getAbsolutePath(path);
  // let contentArray = readdirSync(absPath);
  // let contentList = Array.to_list(contentArray);
  // List.iter((item: string): unit => Js.log("name: " ++ item), contentList);
  // List.iter(item => Js.log("name: " ++ item), contentList);
  // path
  // |> getAbsolutePath
  // |> readdirSync
  // |> Array.to_list
  // |> List.iter(item => Js.log("name:" ++ item));
};