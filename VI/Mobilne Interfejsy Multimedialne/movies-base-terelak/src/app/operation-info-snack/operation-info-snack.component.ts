import { Component, Inject, Input, inject } from '@angular/core';
import { MAT_SNACK_BAR_DATA, MatSnackBarRef } from '@angular/material/snack-bar';

@Component({
  selector: 'app-operation-info-snack',
  templateUrl: './operation-info-snack.component.html',
  styleUrls: ['./operation-info-snack.component.scss']
})
export class OperationInfoSnackComponent {

  @Input()
  snackMessage: string = '';

  snackBarRef = inject(MatSnackBarRef);

  constructor(@Inject(MAT_SNACK_BAR_DATA) public data: any) {
    this.snackMessage = data.message;
  }
}
