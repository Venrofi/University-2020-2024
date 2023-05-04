import { ComponentFixture, TestBed } from '@angular/core/testing';

import { OperationInfoSnackComponent } from './operation-info-snack.component';

describe('OperationInfoSnackComponent', () => {
  let component: OperationInfoSnackComponent;
  let fixture: ComponentFixture<OperationInfoSnackComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ OperationInfoSnackComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(OperationInfoSnackComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
