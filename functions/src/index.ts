import * as functions from "firebase-functions";
import * as _ from "lodash";
import { google } from "googleapis";

const sheets = google.sheets("v4");
const spreadsheetId = "1EK_SoJh501ZCz79o3wbGKBEYZgO61YjGO5NSrmVWOpE";
const serviceAccount = require("../serviceAccount.json");

const jwtClient = new google.auth.JWT({
  email: serviceAccount.client_email,
  key: serviceAccount.private_key,
  scopes: ["https://www.googleapis.com/auth/spreadsheets"] // read and write sheets
});

const jwtAuthPromise = jwtClient.authorize();

export const updateSpreadSheet = functions.database
  .ref("/ac/")
  .onUpdate(async (change, context) => {
    const after = change.after.val();

    const ac_val = context.params.ac;
    console.log(ac_val);

    await jwtAuthPromise;
    
    sheets.spreadsheets.values.append(
      {
        auth: jwtClient,
        spreadsheetId: spreadsheetId,
        range: `A1:C1`, // update this range of cells
        valueInputOption: "RAW",
        requestBody: { values: [[after.time,after.temp,after.hum]] }
      },
      function(err, response) {
        if (err) {
          console.error(err);
          return;
        }
        console.log(JSON.stringify(response, null, 2));
      }
    );
    return 0;
  });
